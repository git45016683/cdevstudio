#ifndef CDEVSTUDIOSYSTEMPLATFORMEXPORT_H
#define CDEVSTUDIOSYSTEMPLATFORMEXPORT_H

#ifdef CDEVSTUDIOSYSTEMPLATFORM_EXPORT
	#define CDEVSTUDIOSYSTEMPLATFORM_API Q_DECL_EXPORT
#else
	#define CDEVSTUDIOSYSTEMPLATFORM_API Q_DECL_IMPORT
#endif

#endif // CDEVSTUDIOSYSTEMPLATFORMEXPORT_H
