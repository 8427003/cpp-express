/*
 *  Copyright (c) 2015-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "HelloWorld.h"

#include <proxygen/httpserver/RequestHandler.h>
#include <proxygen/httpserver/ResponseBuilder.h>
#include <folly/String.h>
#include <folly/dynamic.h>
#include <folly/DynamicConverter.h>
#include <folly/json.h>
#include <glog/logging.h>
#include <folly/futures/Promise.h>
#include <folly/io/async/EventBaseManager.h>

using namespace proxygen;
using google::ERROR;
using google::INFO;

using namespace std;

namespace controllers {

void HelloWorld::onBody(std::unique_ptr<folly::IOBuf> body) noexcept {
  if (body_) {
    body_->prependChain(std::move(body));
  } else {
    body_ = std::move(body);
  }
}

void HelloWorld::onEOM() noexcept {
  LOG(ERROR) << "start2...error...loging..................";
  LOG(INFO) << "start4...info.....loging..................";

  // Create http_client to send the request.
  //http_client client(U("https://www.baidu.com/"));

  //folly::Promise<int> p;
  //folly::Future<int> f = p.getFuture();
  //int i = 0;

  //std::move(f).thenValue([=](int str ){
        //LOG(INFO) << "1111111111111111111111111111";

        string xxx = "555555555555555";
          ResponseBuilder(downstream_)
          .status(200, "OK")
          .header("Request-Number", "123121231233")
          .body(std::move(xxx))
          //.body(std::move(folly::convertTo<std::string>(parsed["aaa"])))
          //.body( std::move(response.to_string()) )
          .sendWithEOM();
  //});
  //auto eventBase = folly::EventBaseManager::get()->getEventBase();
  //client.request(methods::GET).then([=](http_response response) {
        ////LOG(INFO) << response.to_string();
        ////p.setValue(42);

        ////LOG(INFO) << "done=====================";
          //std::string ss = response.to_string();

        //eventBase->runInEventBaseThread([this, ss = std::move(ss)]() mutable {

          //ResponseBuilder(downstream_)
          //.status(200, "OK")
          //.header("Request-Number", "123125")
          //.body(ss)
          ////.body(std::move(folly::convertTo<std::string>(parsed["aaa"])))
          ////.body( std::move(response.to_string()) )
          //.sendWithEOM();
        //});
  //});

  //folly::EventBaseManager::get()->getEventBase()->runInLoop([&]() mutable {
          //LOG(INFO) << i;
          ////p.setValue(42);
 //});

  //folly::EventBaseManager::get()->getEventBase()->runInEventBaseThread([p = std::move(p), this]() mutable {
     //p.setValue(42);
          ////ResponseBuilder(downstream_)
          ////.status(200, "OK")
          ////.header("Request-Number", "123125")
          ////.body(std::move("fdasdf"))
          //////.body(std::move(folly::convertTo<std::string>(parsed["aaa"])))
          //////.body( std::move(response.to_string()) )
          ////.sendWithEOM();
  //});
}

void HelloWorld::requestComplete() noexcept {
  delete this;
}

void HelloWorld::onError(ProxygenError /*err*/) noexcept {
  delete this;
}

} // namespace controllers
