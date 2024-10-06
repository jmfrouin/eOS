//
// Created by Jean-Michel Frouin on 06/10/2024.
//

#ifndef CONFIG_H
#define CONFIG_H

#include "Def.h"

namespace Core {

    /**
     * @class CConfig
     * @brief Manages configuration settings for the application.
     */
    class CConfig {

        public:
            /**
             * @brief Constructs a new CConfig object.
             */
            CConfig();

            /**
             * @brief Destroys the CConfig object.
             */
            ~CConfig();

            /**
             * @brief Loads the configuration settings.
             * @return EErrors indicating success or failure.
             */
            EErrors LoadConfiguration();

            /**
             * @brief Saves the configuration settings.
             * @return EErrors indicating success or failure.
             */
            EErrors SaveConfiguration();

        public:
            int mPort; /**< Port number for the configuration. */

    };

} // Core

#endif //CONFIG_H