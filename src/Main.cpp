// @Author Lin Ya
// @Email xxbbb@vip.qq.com
#include "EventLoop.h"
#include "Server.h"
#include <getopt.h>
#include <string>
#include <charon/mvm>
#include <charon/base>

using mvm     = charon::mvm;
using Log     = charon::Log;
using service = charon::service;



int main(int argc, char *argv[])
{
    mvm::init(argc, argv);
    bool service  = true;
    int  threadNum = os::cores();
    int  port = 2345;

    // parse args
    int opt;
    const char *str = "t:l:p:";
    while ((opt = getopt(argc, argv, str))!= -1)
    {
        switch (opt)
        {
            case 't':
            {
                threadNum = atoi(optarg);
                break;
            }
            case 'p':
            {
                port = atoi(optarg);
                break;
            }
            default: break;
        }
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
