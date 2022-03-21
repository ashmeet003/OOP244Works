#include "Status.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
    Status::Status(char* statusDesc)
    {
        m_statusDesc = nullptr;
        ut.alocpy(m_statusDesc, statusDesc);
        m_statusCode = 0;
    }

    Status::Status(const Status& S)
    {
        m_statusDesc = nullptr;
        ut.alocpy(m_statusDesc, S.m_statusDesc);
        m_statusCode = S.m_statusCode;
    }
   
    Status& Status::operator=(const Status& S)
    {
        if (this != &S){
            ut.alocpy(m_statusDesc, S.m_statusDesc);
            m_statusCode = S.m_statusCode;
        }
        return *this;
    }
   
    Status::~Status()
    {
        delete[] m_statusDesc;
    }
    
    Status& Status::operator=(const char* statusDesc)
    {
        ut.alocpy(m_statusDesc, statusDesc);
        return *this;
    }
   
    Status& Status::operator=(int code)
    {
        m_statusCode = code;
        return *this;
    }
    Status::operator int() const
    {
        return m_statusCode;
    }
    
    Status::operator char* () const
    {
        return m_statusDesc;
    }
    
    Status::operator bool() const
    {
        return m_statusDesc == nullptr;
    }
   
    Status& Status::clear()
    {
        delete[] m_statusDesc;
        m_statusDesc = nullptr;
        m_statusCode = 0;
        return *this;
    }
    const char* Status::getDesc() const
    {
        return m_statusDesc;
    }
    int Status::getCode() const
    {
        return m_statusCode;
    }
   
    ostream& operator<<(ostream& ostr, const Status& S)
    {
        if (!S){
            if (S.getCode() != 0){
                ostr << "ERR#" << S.getCode() << ": ";
            }
            ostr << S.getDesc();
        }
        return ostr;
    }
}
