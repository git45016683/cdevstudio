#ifndef CDEVSTUDIOPROJECTPLATFORMEXPORT_H
#define CDEVSTUDIOPROJECTPLATFORMEXPORT_H

#ifdef CDEVSTUDIOPROJECTPLATFORM_EXPORT
	#define CDEVSTUDIOPROJECTPLATFORM_API Q_DECL_EXPORT
#else
	#define CDEVSTUDIOPROJECTPLATFORM_API Q_DECL_IMPORT
#endif

#endif // CDEVSTUDIOPROJECTPLATFORMEXPORT_H