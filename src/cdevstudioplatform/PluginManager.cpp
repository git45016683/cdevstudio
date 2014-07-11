#include "PluginManager.h"

PluginManager::PluginManager(QObject *parent) : QObject(parent)
{
#ifdef Q_OS_WIN
	QCoreApplication::addLibraryPath("C:/Program Files/cdevstudio-workspace/bin");
#else
	QCoreApplication::addLibraryPath("/usr/bin");
#endif
}

QList<IPlugin *> PluginManager::getPlugins()
{
	if(m_Plugins.count() == 0)
	{
		foreach(QString path, QCoreApplication::libraryPaths())
		{
			foreach(QString filename, Backend::getFilesInDirectory(path))
			{
				QString file = path + QString("/") + filename;
				if(QLibrary::isLibrary(file))
				{
					QPluginLoader loader(file, this);
					IPlugin *plugin = qobject_cast<IPlugin *>(loader.instance());
					if(plugin != nullptr && !m_Plugins.contains(plugin))
					{
						m_Plugins.append(plugin);
						qDebug() << "[PluginManager] Plugin loaded";
					}
				}
			}
		}
	}
	return m_Plugins;
}
