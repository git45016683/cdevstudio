#ifndef CDEVSTUDIOPLATFORMEXPORT_H
#define CDEVSTUDIOPLATFORMEXTERN_H

#ifdef CDEVSTUDIOPLATFORM_EXPORT
	#define CDEVSTUDIOPLATFORM_API Q_DECL_EXPORT
#else
	#define CDEVSTUDIOPLATFORM_API Q_DECL_IMPORT
#endif

#endif // CDEVSTUDIOPLATFORMEXPORT_H
