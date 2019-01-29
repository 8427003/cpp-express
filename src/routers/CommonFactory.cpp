/*
 *  Copyright (c) 2015-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include "../controllers/HelloWorld.h"
#include "CommonFactory.h"

#include <proxygen/httpserver/RequestHandler.h>
#include <proxygen/httpserver/ResponseBuilder.h>

using namespace proxygen;

namespace routers {

void CommonFactory::onServerStart(folly::EventBase* /*evb*/) noexcept  {}

void CommonFactory::onServerStop() noexcept {}

RequestHandler* CommonFactory::onRequest(RequestHandler*, HTTPMessage*) noexcept {
    return new controllers::HelloWorld();
}

}
