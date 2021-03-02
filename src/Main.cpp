// Copyright 2015 Lin Ya (xxbbb@vip.qq.com)
// Copyright 2016 The Arken Platform Authors.
// All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <string>
#include <QJsonObject>
#include "EventLoop.h"
#include "Server.h"
#include <getopt.h>
#include <arken/mvm>
#include <arken/base>
#include <arken/log.h>
#include <arken/net/config.h>

using mvm     = arken::mvm;
using Log     = arken::Log;
using Config  = arken::net::Config;

int main(int argc, char *argv[])
{
    mvm::init(argc, argv);

    Config c("config/titan.json");
    std::cout << "start titan " << c.address() << ":" << c.port() <<
      " (" << c.threads() << ") threads..." << std::endl;
    /*
    bool service       = true;
    int  threadNum     = 4;
    int  port          = 2345;
    arken::string pid = "titan.pid";

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
      arken::service::load("app/services");
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
    */

    EventLoop mainLoop;
    Server myHTTPServer(&mainLoop, c.threads() , c.port());
    myHTTPServer.start();
    mainLoop.loop();
    return 0;
}
