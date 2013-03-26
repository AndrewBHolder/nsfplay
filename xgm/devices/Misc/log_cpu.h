#ifndef _LOG_CPU_H_
#define _LOG_CPU_H_

#include "../device.h"
#include <cstdio>

namespace xgm
{

class CPULogger : public IDevice
{
public:
    CPULogger();
    virtual ~CPULogger();

    // IDevice virtuals
    virtual void Reset ();
    virtual bool Write (UINT32 adr, UINT32 val, UINT32 id=0);
    virtual bool Read (UINT32 adr, UINT32 & val, UINT32 id=0);
    virtual void SetOption (int id, int val);

    // CPULogger specific
    int GetLogLevel () const;
    void SetSoundchip (UINT8 soundchip_);
    void SetFilename (const char * filename_);
    void Begin (const char* title);
    void Init (UINT8 reg_a, UINT8 reg_x);
    void Play ();

protected:
    int log_level;
    UINT8 soundchip;
    FILE* file;
    char* filename;
};

}

#endif