#ifdef SE_WINDOWS
	#ifdef _DLL
		#define _API __declspec(dllexport)
	#else 
		#define _API __declspec(dllimport)
	#endif
#else
	#ifdef _DLL
		#define _API __attribute__((visibility("default")))
	#else 
		#define _API
	#endif
#endif
