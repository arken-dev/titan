// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#include "EventLoop.h"
#include "Server.h"
#include <getopt.h>
#include <string>
#include <charon/mvm>
#include <charon/base>

#include <QJsonObject>

using mvm     = charon::mvm;
using Log     = charon::Log;
using service = charon::service;

int main(int argc, char *argv[])
{
    mvm::init(argc, argv);

    bool service       = true;
    int  threadNum     = 4;
    int  port          = 2345;
    charon::string pid = "titan.pid";

    // TODO change without Qt JSON reader
    QFile config("config/titan.json");
    if( config.exists() ) {
      config.open(QIODevice::ReadOnly);
      QJsonParseError * error = new QJsonParseError();
      QJsonDocument json = QJsonDocument::fromJson(config.readAll(), error);
      if( error->error != 0 ) {
        qDebug() << error->errorString();
        throw;
      }
      QJsonObject object = json.object();
      port      = object.value("port").toInt();
      threadNum = object.value("threads").toInt();
      pid       = object.value("pid").toString().toLocal8Bit();
      service   = object.value("service").toBool();
    } else {
      qDebug() << "config/titan.json file not exists";
    }

    // SERVICES
    if( service && os::exists("app/services")) {
      charon::service::load("app/services");
    }

    if( os::exists("logs") ) {
      Log log = Log("logs/titan.log");
      log.info("iniciando titan");
      if( service ) {
        if( os::exists("app/services") ) {
          log.info("services started");
        } else {
          log.info("services dir not exists");
        }
      } else {
        log.info("services not enable");
      }
      log.dump();
    }

    EventLoop mainLoop;
    Server myHTTPServer(&mainLoop, threadNum, port);
    myHTTPServer.start();
    mainLoop.loop();
    return 0;
}
