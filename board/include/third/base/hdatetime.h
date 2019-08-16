
#ifndef __HDATA_TIME_H__
#define __HDATA_TIME_H__

#include <string>
#if defined(_WIN32)
	#define WIN32_LEAN_AND_MEAN
	#include <windows.h>
	#include <comdef.h>
#endif
#include "hdefines.h"

namespace HDSOFT
{

enum HTimeStatus
{
	valid = 0,
	invalid = 1,    // Invalid date (out of range, etc.)
	null = 2,       // Literally has no value
};

typedef enum _HDateType
{
	HDATETYPE_DATETIME,
	HDATETYPE_DATE,
	HDATETYPE_TIME,
	HDATETYPE_UTC,
}HDATE_TYPE;

class CHDateTimeSpan;
class CHDateTime
{
public:
	CHDateTime();
	CHDateTime(const CHDateTime& dateSrc);
#if defined(_WIN32)
	CHDateTime(const VARIANT& varSrc);
#endif
	CHDateTime(double dtSrc);
	CHDateTime(time_t timeSrc);
	CHDateTime(const struct tm & tmSrc);
	CHDateTime(long nYear,long nMonth,long nDay,long nHour,long nMin,long nSec,long nMilliSec=0);
	virtual ~CHDateTime();

public:
	void				SetStatus(HTimeStatus status);
	HTimeStatus			GetStatus() const;
	bool				IsValid() const;

public:
	const CHDateTime& operator=(const CHDateTime& dateSrc);
#if defined(_WIN32)
	const CHDateTime& operator=(const VARIANT& varSrc);
#endif
	const CHDateTime& operator=(double dtSrc);
	const CHDateTime& operator=(const time_t& timeSrc);
	const CHDateTime& operator=(const struct tm& tmSrc);

	bool operator==(const CHDateTime& date) const;
	bool operator!=(const CHDateTime& date) const;
	bool operator<(const CHDateTime& date) const;
	bool operator>(const CHDateTime& date) const;
	bool operator<=(const CHDateTime& date) const;
	bool operator>=(const CHDateTime& date) const;

	CHDateTime operator+(const CHDateTimeSpan& dateSpan) const;
	CHDateTime operator-(const CHDateTimeSpan& dateSpan) const;
	const CHDateTime& operator+=(const CHDateTimeSpan dateSpan);
	const CHDateTime& operator-=(const CHDateTimeSpan dateSpan);

	CHDateTimeSpan operator-(const CHDateTime& date) const;
	operator			double() const	{ return m_dt; }

	bool				AddDay(long spanDay =1);
	bool				AddMonth(long spanMon =1);	// The increase / decrease month, the subsequent part of the date is unchanged. If the original date is the last day of the month, the last day of the month after the change will exceed, automatically adjust. 
	bool				AddYear(long spanYear =1);	// Increase / decrease the year, the other part of the date is unchanged. If the original date is the leap year  February 29th, it will change to the nonleap year, then automatically turn into February 28th.
	bool				AddHour(long spanHour =1);
	bool				AddMinute(long spanMin =1);
	bool				AddSecond(long spanSec =1);
	bool				AddMilliSecond(long spanMilli =1);

	int					SetDateTime(long nYear,long nMonth,long nDay,long nHour,long nMin,long nSec,long nMilliSec);
	int					SetDate(long nYear,long nMonth,long nDay);
	int					SetTime(long nHour,long nMin,long nSec,long nMilliSec);

	ULONGLONG			GetNTPTime(bool ignorezeno=true);
#if defined(_WIN32)
	bool				ParseDateTime(const char * lpszDate, DWORD dwFlags=0, LCID lcid= LANG_USER_DEFAULT );
#endif

	bool				Parse(const char * lpszDate,int nDateType);
public:
	//GetXXX return datetime is after 1970-01-01
	long				GetYear() const;
	long				GetMonth() const;			// month of year (1 = 1month)
	long				GetDay() const;				// day of month (1-31)
	long				GetHour() const;			// hour in day (0-23)
	long				GetMinute() const;			// minute in hour (0-59)
	long				GetSecond() const;			// second in minute (0-59)
	long				GetMilliSecond() const;
	long				GetDayOfWeek() const;		// The day of the week represented by the value,1=Monday, 2=Tuesday, ..., 7=Sunday
	long				GetDayOfYear() const;		// The day of the year represented by the value , January 1st = 1
	long				GetWeekIndex() const;		// The week of the month represented by the value

	CHDateTime			GetMonthFirstDay() const;		// Return to the first day of the month
	CHDateTime			GetMonthLastDay() const;		// Return to the last day of the month
	CHDateTime			GetYearFirstDay() const;		// Return to the first day of the year
	CHDateTime			GetYearLastDay() const;			// Return to the last day of the year
	
	// Return to the specified weeks of the week in which month, bAllowPrevMonth shows true permission to return to last month.
	CHDateTime			GetMonthOneDay(int nWeekIndex,int nWeek,bool bAllowPrevMonth=false) const;

	bool				IsMonthFirstDay() const;	//return true it is the first day of the month
	bool				IsMonthLastDay() const;		//retuen true it is the last day of the month
	bool				IsYearFirstDay() const;		//return true it is the first day of the year
	bool				IsYearLastDay() const;		//return true it is the last day of the year
	bool				IsLeapYear() const;			//return true it is the leap year
	
	bool				IsSameYear(const CHDateTime & date) const;
	bool				IsSameMonth(const CHDateTime & date) const;
	bool				IsSameDay(const CHDateTime & date) const;
	
	bool				GetTM(struct tm &tmDest);	//the tmDest is local time
	std::string			toString() const;
	std::string			toStandardString() const;

	//timeznoe:The decimal part means minutes.For example 8.5 means 8 hour 30 minutes
	std::string			toUTCString(bool withmillisec=false,float timeznoe=0.0) const;
	std::string			Format(const char * pFormat) const;

	static bool			Date2Tm(const double dtSrc, struct tm &tmDest, WORD &wMilliSec);
	static bool			Tm2Date(const struct tm tmSrc, WORD wMilliSec, double &dtDest);
	static bool			Tm2Date(WORD wYear,WORD wMonth,WORD wDay,WORD wHour,WORD wMinute,WORD wSecond,WORD wMilliSec,double& dtDest);
	static bool			IsLeapYear(WORD wYear);
	static CHDateTime	GetCurrentTime();
protected:
	void				CheckRange();
	double				m_dt;	
	HTimeStatus			m_status;
};

class CHDateTimeSpan
{
public:
	CHDateTimeSpan();
	CHDateTimeSpan(const CHDateTime& dateSrc);
	CHDateTimeSpan(double dblSpanSrc);
	CHDateTimeSpan(const CHDateTimeSpan& dateSpanSrc);
	CHDateTimeSpan(long lDays, int nHours, int nMins, int nSecs);
	CHDateTimeSpan(long lDays, int nHours, int nMins, int nSecs, int nMilliSecs);
public:
	void SetStatus(HTimeStatus status);
	HTimeStatus GetStatus() const;

	double				GetTotalDays() const;    // span in days (about -3.65e6 to 3.65e6)
	long				GetTotalHours() const;   // span in hours (about -8.77e7 to 8.77e6)
	long				GetTotalMinutes() const; // span in minutes (about -5.26e9 to 5.26e9)
	long				GetTotalSeconds() const; // span in seconds (about -3.16e11 to 3.16e11)
	long				GetTotalMilliSeconds() const;

	long				GetDays() const;       // component days in span
	long				GetHours() const;      // component hours in span (-23 to 23)
	long				GetMinutes() const;    // component minutes in span (-59 to 59)
	long				GetSeconds() const;    // component seconds in span (-59 to 59)
	long				GetMilliSeconds() const;
// Operations
public:
	const CHDateTimeSpan& operator=(double dblSpanSrc);
	const CHDateTimeSpan& operator=(const CHDateTimeSpan& dateSpanSrc);

	bool operator==(const CHDateTimeSpan& dateSpan) const;
	bool operator!=(const CHDateTimeSpan& dateSpan) const;
	bool operator<(const CHDateTimeSpan& dateSpan) const;
	bool operator>(const CHDateTimeSpan& dateSpan) const;
	bool operator<=(const CHDateTimeSpan& dateSpan) const;
	bool operator>=(const CHDateTimeSpan& dateSpan) const;

	// DateTimeSpan math
	CHDateTimeSpan operator+(const CHDateTimeSpan& dateSpan) const;
	CHDateTimeSpan operator-(const CHDateTimeSpan& dateSpan) const;
	const CHDateTimeSpan& operator+=(const CHDateTimeSpan dateSpan);
	const CHDateTimeSpan& operator-=(const CHDateTimeSpan dateSpan);
	CHDateTimeSpan operator-() const;

	operator double() const;

	void				SetDateTimeSpan(long lDays, int nHours, int nMins, int nSecs, int nMilliSecs=0 );
protected:	
	void				CheckRange();
	double				m_span;
	HTimeStatus			m_status;
	friend class 		CHDateTime;
};

}//namespace HDSOFT
#endif

