/*
 * Copyright (c) 2019-2020 Waqar Ahmed -- <waqar.17a@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 */
#ifndef QOWNLANGUAGEDATA_H
#define QOWNLANGUAGEDATA_H

template<typename key, typename val>
class QMultiHash;

class QLatin1String;

namespace QSourceHighlite {

using LanguageData = QMultiHash<char, QLatin1String>;

/**********************************************************/
/* C/C++ Data *********************************************/
/**********************************************************/
void loadCppData(LanguageData &typess,
             LanguageData &keywordss,
             LanguageData &builtins,
             LanguageData &literalss,
             LanguageData &others);

/**********************************************************/
/* Shell Data *********************************************/
/**********************************************************/
void loadShellData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/**********************************************************/
/* JS Data *********************************************/
/**********************************************************/
void loadJSData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/**********************************************************/
/* PHP Data *********************************************/
/**********************************************************/
void loadPHPData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/**********************************************************/
/* QML Data *********************************************/
/**********************************************************/
void loadQMLData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/**********************************************************/
/* Python Data *********************************************/
/**********************************************************/
void loadPythonData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   Rust DATA      ***********************************/
/********************************************************/
void loadRustData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   Java DATA      ***********************************/
/********************************************************/
void loadJavaData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   C# DATA      *************************************/
/********************************************************/
void loadCSharpData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   Go DATA      *************************************/
/********************************************************/
void loadGoData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   V DATA      **************************************/
/********************************************************/
void loadVData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   SQL DATA      ************************************/
/********************************************************/
void loadSQLData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   JSON DATA      ***********************************/
/********************************************************/
void loadJSONData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   CSS DATA      ***********************************/
/********************************************************/
void loadCSSData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   Typescript DATA  *********************************/
/********************************************************/
void loadTypescriptData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   YAML DATA  ***************************************/
/********************************************************/
void loadYAMLData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   VEX DATA   ***************************************/
/********************************************************/
void loadVEXData(LanguageData &types,
             LanguageData &keywords,
             LanguageData &builtin,
             LanguageData &literals,
             LanguageData &other);

/********************************************************/
/***   CMake DATA  **************************************/
/********************************************************/
void loadCMakeData(QMultiHash<char, QLatin1String> &types,
             QMultiHash<char, QLatin1String> &keywords,
             QMultiHash<char, QLatin1String> &builtin,
             QMultiHash<char, QLatin1String> &literals,
             QMultiHash<char, QLatin1String> &other);

/********************************************************/
/***   Make DATA  ***************************************/
/********************************************************/
void loadMakeData(QMultiHash<char, QLatin1String>& types,
    QMultiHash<char, QLatin1String>& keywords,
    QMultiHash<char, QLatin1String>& builtin,
    QMultiHash<char, QLatin1String>& literals,
    QMultiHash<char, QLatin1String>& other);

void loadAsmData(QMultiHash<char, QLatin1String>& types,
    QMultiHash<char, QLatin1String>& keywords,
    QMultiHash<char, QLatin1String>& builtin,
    QMultiHash<char, QLatin1String>& literals,
    QMultiHash<char, QLatin1String>& other);
}
#endif
