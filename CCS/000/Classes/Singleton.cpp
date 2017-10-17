#include <Singleton.h>
#include <stddef.h>

Singleton* Singleton::m_pInstance = NULL;

Singleton* Singleton::getInstance()
{
	if (!m_pInstance)
	{
		m_pInstance = new Singleton;
	}

	return m_pInstance;
}
