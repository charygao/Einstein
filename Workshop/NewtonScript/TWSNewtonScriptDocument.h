//
//  TWSNewtonScriptDocument.h
//  Einstein
//
//  Created by Matthias Melcher on 3/6/17.
//
//

#ifndef TWSNewtonScriptDocument_h
#define TWSNewtonScriptDocument_h

#include "Workshop/TWSProjectItem.h"


class TWSNewtonScriptDocument : public TWSProjectItem
{
public:
	TWSNewtonScriptDocument(TWorkshop*);
	~TWSNewtonScriptDocument();
	virtual const char *GetIcon() { return "tree_nsc.png"; }
	virtual bool CreateEditor(void *inParentView);
	void AssociateFile(const char *inFilename);
	char *GetText();

protected:
	char *pFilename;	// TODO: currently, this is the full path and name. We will need to differentiate this form the project relative filename
};



// ---- the functions below provide a platform independent interface to create
//		and manage the UI for NewtonScript Workshop Project Items.
//		These must be implemented in the platform specific UI file.

typedef void (*TWSNewtonScriptEditorCallback)(void *inEditor);

// create and destroy a NewtonScript editor interface
void *NewtonScriptEditorCreate(TWSNewtonScriptDocument *inItem, void* inParentView);
void NewtonScriptEditorDestroy(void *inEditor);

// Set and get the text in the editor
void NewtonScriptEditorSetText(void *inEditor, const char *text);
const char* NewtonScriptEditorGetText(void *inEditor);

// Receive messages from the UI
void NewtonScriptEditorChangedCallback(TWSNewtonScriptEditorCallback* inCallback);


#endif /* TWSNewtonScriptDocument_h */