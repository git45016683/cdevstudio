#ifndef PLATFORM_H
#define PLATFORM_H

#include <QtCore/QObject>
#include <QtCore/QList>

#include "PlatformExport.h"
#include "IPlatform.h"
#include "PluginManager.h"
#include "ProjectManager.h"
#include "Window.h"
#include "Window.h"

class CDEVSTUDIOPLATFORM_EXPORT Platform : public IPlatform
{
	Q_OBJECT
	
public:
	Platform(Window *window);
	PluginManager *getPluginManager();
	ProjectManager *getProjectManager();
	Window *getWindow();
	
private:
	PluginManager *m_PluginManager;
	ProjectManager *m_ProjectManager;
	Window *m_Window;
};

#endif // PLATFORM_H
