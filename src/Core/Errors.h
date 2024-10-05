//
// Created by Jean-Michel Frouin on 17/11/2023.
//

#ifndef _ERRORS_H
#define _ERRORS_H

namespace Core
{
    enum EErrors
    {
        eNoError = 0,

        //Generic
        eCannotOpenFile = 1,
        eCannotDeleteLogFile = 2,
        eConfEmpty = 3,
        eCannotOpenPath = 4,
        eAccessDenied = 5,
        eUnknown = 6
    };
}

#endif
