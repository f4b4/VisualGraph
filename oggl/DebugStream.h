#ifdef _WIN32

// undefines the macros min and max which are specified in the windows headers
// prevents this error on using std::max etc.:
// error C2589: '(' : illegal token on right side of '::'
#define NOMINMAX

#include <Windows.h>

#endif // _WIN32

#ifdef __linux__

#include <stdio.h>
#include <unistd.h>
#include <syslog.h>

#endif // __linux__

#include <ostream>
#include <sstream>
#include <string>

// http://www.codeproject.com/Articles/1053/Using-an-output-stream-for-debugging
// http://www.c.happycodings.com/Gnu-Linux/code21.html

// example, conclude statement with std::endl to flush stream
//
//    #ifdef _DEBUG
//        oggl::dout << "GraphWidget::OnHScrollValueChanged" << ": value=" << value << std::endl;
//    #endif

// view output:
// * Windows: VisualStudio or DebugView
// * linux: tail -f /var/log/syslog 
//          sudo tail -f /var/log/messages

namespace oggl {

template <class CharT, class TraitsT = std::char_traits<CharT> >
class DebugStringBuffer :
	public std::basic_stringbuf<CharT, TraitsT>
{
	std::stringstream m_stream;

public:

	virtual ~DebugStringBuffer()
	{
		sync();
	}

protected:

	int sync()
	{
		output_debug_string(this->str().c_str());
		this->str(std::basic_string<CharT>());    // Clear the string buffer

		return 0;
	}

	void output_debug_string(const CharT *text) {}
};

template<>
inline void DebugStringBuffer<char>::output_debug_string(const char *text)
{
#ifdef _WIN32
	::OutputDebugStringA(text);
#endif

#ifdef __linux__
	openlog(0, LOG_PID | LOG_CONS, LOG_USER);
	syslog(LOG_INFO, text);
	closelog();
#endif // __linux__
}

template<class CharT, class TraitsT = std::char_traits<CharT> >
class DebugOutStream :
	public std::basic_ostream<CharT, TraitsT>
{
	DebugStringBuffer<CharT, TraitsT> m_buffer;

public:

	DebugOutStream()
		: std::basic_ostream<CharT, TraitsT>(&m_buffer)
	{
	}

	~DebugOutStream()
	{
	}
};

extern DebugOutStream<char> dout;
}
