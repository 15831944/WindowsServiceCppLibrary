#ifndef __BUILDCOREMACRO_HPP__
#define __BUILDCOREMACRO_HPP__
#ifdef WINSVCLIB_SHARED_BUILD
#if defined(SERVICECREATE_EXPORTS) || defined(INSTALLER_EXPORTS) || defined(UNINSTALLER_EXPORTS)
#define 
#define WINSVCBUILD __declspec(dllexport)
#else
#define WINSVCBUILD __declspec(dllimport)
#endif
#else
#define WINSVCBUILD
#endif
#endif 
