/*
 *  reswin.hpp
 *  SimpleChess
 *
 *  Created by Ronak Gajrawala on 12/01/13.
 *  Copyright (c) 2013-2015 Ronak Gajrawala. All rights reserved.
 */

#ifndef SimpleChess_resources_hpp
#define SimpleChess_resources_hpp

namespace SimpleChess {
	/**
	 * The Resources class.
	 * Used for anything involving file paths of resources.
	 */
	namespace Resources {
		std::string ResourcePath = "./"; /**< The resource path has to be set manually by the user in Windows. */

		/*
		 * Sets ResourcePath.
		 * @param path The new resource folder path in Windows.
		 */
		void SetPath(const std::string);

		/*
		 * Gets the resource file path in Windows.
		 * @param file The file name of the resource file in Windows.
		 * @return The resource file path in Windows.
		 */
		std::string GetResource(const std::string);
	};
};

void SimpleChess::Resources::SetPath(const std::string path) {
	ResourcePath = path;
}

std::string SimpleChess::Resources::GetResource(const std::string file) {
	return ResourcePath + file;
}

#endif
