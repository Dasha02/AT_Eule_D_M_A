#ifndef KFVERIFIER_H
#define KFVERIFIER_H

#include "kfverifier_global.h"
#include <ATGUI/APlugin.h>

class ATaskExecutionWindow;
class KFVERIFIERSHARED_EXPORT KFVerifier : public AUtilityPlugin
{

public:
    KFVerifier();
    ~KFVerifier();

public:
    int executeTask(ATaskExecutionWindow *wnd, const std::string &cmd_id, const std::vector<ADocumentRef *> &input_docs, const std::vector<ADocumentRef *> &out_docs);
    // AUtilityPlugin interface;

public:
    const std::vector<std::string> getCommands();
    AError executeCommand(const std::string &script, std::string &answer);

};

#endif // KFVERIFIER_H
