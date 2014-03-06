/*
 *  reswin.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_reswin_hpp
#define SimpleChess_reswin_hpp

namespace SimpleChess {
    namespace Resources {
        std::string ResourcePath = "./"; /**< The resource path has to be set manually by the user in Windows. */
        
        void SetPath(std::string path) {
            ResourcePath = path;
        }
        
        const std::string GetResource(const std::string file) {
        	return ResourcePath + file;
        }
    };
};

#endif
