#ifndef CHATLOGIC_H_
#define CHATLOGIC_H_

#include "chatgui.h"
#include <memory>
#include <string>
#include <vector>

using std::unique_ptr;
using std::vector;

// forward declarations
class ChatBot;
class GraphEdge;
class GraphNode;

class ChatLogic {
private:
  // data handles (owned)
  vector<unique_ptr<GraphNode>> _nodes;

  // data handles (not owned)
  GraphNode *_currentNode;
  ChatBot *_chatBot;
  ChatBotPanelDialog *_panelDialog;

  // proprietary type definitions
  typedef std::vector<std::pair<std::string, std::string>> tokenlist;

  // proprietary functions
  template <typename T>
  void AddAllTokensToElement(std::string tokenID, tokenlist &tokens,
                             T &element);

public:
  // constructor / destructor
  ChatLogic();
  ~ChatLogic();
  // getter / setter
  void SetPanelDialogHandle(ChatBotPanelDialog *panelDialog);
  void SetChatbotHandle(ChatBot *chatbot);
  // proprietary functions
  void LoadAnswerGraphFromFile(std::string filename);
  void SendMessageToChatbot(std::string message);
  void SendMessageToUser(std::string message);
  wxBitmap *GetImageFromChatbot();
};

#endif /* CHATLOGIC_H_ */