/*
 *  Copyright (c) 2015-present, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */

#pragma once

#include <proxygen/httpserver/RequestHandlerFactory.h>
#include <proxygen/httpserver/RequestHandler.h>

using namespace proxygen;

namespace routers {

class CommonFactory : public RequestHandlerFactory {
    public:
        void onServerStart(folly::EventBase* /*evb*/) noexcept override;
        void onServerStop() noexcept override;

    RequestHandler* onRequest(RequestHandler*, HTTPMessage*) noexcept override;
};

}
