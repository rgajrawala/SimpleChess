/*
 *  reswin.hpp
 *  ChessPlusPlus
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013 Ronak Gajrawala. All rights reserved.
 */

#ifndef ChessPlusPlus_reswin_hpp
#define ChessPlusPlus_reswin_hpp

const std::string ResourcePath = "res/"; /**< The resource path has to be set manually by the user in Windows. */

const std::string GetResource(const std::string file) {
	return ResourcePath + file;
}

#endif
