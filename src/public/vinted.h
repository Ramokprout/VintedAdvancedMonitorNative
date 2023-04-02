#ifndef __VINTED_MAINCLASS__
#define __VINTED_MAINCLASS__

#include <memory>
#include "vintedlogger.h"
#include "vintedrest.h"
#include "vinteddata.h"


class vinted
{
public:
    vinted()
    {
        this->m_logger = std::shared_ptr<vintedlogger>(new vintedlogger());
        this->m_rest = new vintedrest(this->m_logger);
        this->m_data = new vinteddata(this->m_rest);
    }

    vintedrest *GetRest() const
    {
        return this->m_rest;
    }

    vinteddata *GetData() const {
        return this->m_data;
    }

    std::shared_ptr<vintedlogger> GetLogger() const {
        return this->m_logger;
    }

    ~vinted()
    {
        delete this->m_rest;
    }

private:
    vintedrest *m_rest;
    vinteddata *m_data;
    std::shared_ptr<vintedlogger> m_logger;
};

#endif