#include <string>
#include "EventLoop.h"
#include "Server.h"
#include <getopt.h>

#include <arken/net/httpserver.h>
#include <arken/mvm.h>
#include <arken/base>

using HttpServer = arken::net::HttpServer;


//-----------------------------------------------------------------------------
// HTTP SERVER RUN
//-----------------------------------------------------------------------------

void HttpServer::run()
{
  std::cout << "start arken.net.HttpServer (titan) " << m_address <<
    ":" << m_port << " (" << m_threads << ") threads..." << std::endl;

  EventLoop mainLoop;
  Server myHTTPServer(&mainLoop, m_threads, m_port);
  myHTTPServer.start();
  mainLoop.loop();
}

