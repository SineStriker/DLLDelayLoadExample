#include <Windows.h>

#include <iostream>
#include <ctime>

_EXTERN_C
#include <libavcodec/avcodec.h>
_END_EXTERN_C

#pragma comment(lib, "C:\\Users\\truef\\Documents\\GitHub\\DLLDelayLoadExample\\lib\\avcodec.lib")
#pragma comment(lib, "delayimp.lib")

int main(int argc, char *argv[]) {
    std::cout << "Hello World!" << std::endl;

    // Get current directory
    std::wstring wstr;
    unsigned long size = ::GetCurrentDirectoryW(0, NULL);
    wchar_t *buf = new wchar_t[size];
    if (::GetCurrentDirectoryW(size, buf) != 0) {
        wstr = buf;
    } else {
        std::cout << "Failed to get current directory!" << std::endl;
        return -1;
    }
    delete[] buf;

    wstr += L"\\lib\\";

    ::SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_APPLICATION_DIR |
                               LOAD_LIBRARY_SEARCH_DEFAULT_DIRS | LOAD_LIBRARY_SEARCH_SYSTEM32 |
                               LOAD_LIBRARY_SEARCH_USER_DIRS);
    ::AddDllDirectory(wstr.data());

    std::cout << "Dll directory added." << std::endl;

    std::cout << avcodec_version() << std::endl;

    return 0;
}