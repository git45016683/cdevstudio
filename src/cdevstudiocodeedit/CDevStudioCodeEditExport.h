#ifndef CDEVSTUDIOCODEEDITEXPORT_H
#define CDEVSTUDIOCODEEDITEXPORT_H

#ifdef CDEVSTUDIOCODEEDIT_EXPORT
	#define CDEVSTUDIOCODEEDIT_API Q_DECL_EXPORT
#else
	#define CDEVSTUDIOCODEEDIT_API Q_DECL_IMPORT
#endif

#endif // CDEVSTUDIOCODEEDITEXPORT_H
