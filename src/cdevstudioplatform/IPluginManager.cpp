#include "IPluginManager.h"

IPluginManager::IPluginManager(): QObject()
{

}

IPluginManager::~IPluginManager()
{
	qDeleteAll<>(m_Plugins);
}

void IPluginManager::loadPlugins()
{
	foreach(QString path, getPluginDirectories())
	{
		QStringList files = QDir(path).entryList(getPluginFilter());
		foreach(QString file, files)
		{
			QPluginLoader loader(path + QString("/") + file, this);
			IPlugin *plugin = qobject_cast<IPlugin *>(loader.instance());
			if(plugin != nullptr)
			{
					m_Plugins.append(plugin);
			}
			else
			{
				qDebug() << "Error:" << loader.errorString();
			}
		}
	}
}

QList<IPlugin *> IPluginManager::getPlugins()
{
	return m_Plugins;
}

IPlugin *IPluginManager::getPlugin(QString name)
{
	IPlugin *searchplugin = nullptr;
	foreach(IPlugin *plugin, m_Plugins)
	{
		if(name.compare(plugin->getName()) == 0)
		{
			searchplugin = plugin;
		}
	}
	return searchplugin;
}

QStringList IPluginManager::getPluginFilter()
{
	QStringList filter;
	filter << QString("*plugin*.dylib");
	filter << QString("*plugin*.dll");
	filter <<  QString("*plugin*.so");
	return filter;
}

QStringList IPluginManager::getPluginDirectories()
{
	QStringList directories;
	
#ifdef Q_OS_WIN
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/plugincore/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginproject/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectdata/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectwizard/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginprojectexplorer/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginsettings/";
	directories << "C:/Users/User/Downloads/cdevstudio/build/src/pluginhelp/";
#else
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/plugincore/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginproject/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectdata/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectwizard/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginprojectexplorer/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginsettings/";
	directories << "/home/swaechter/Workspace_C++/cdevstudio/build/src/pluginhelp/";
#endif
	
	return directories;
}
