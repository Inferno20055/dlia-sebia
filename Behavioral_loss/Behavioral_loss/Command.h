#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

class TextEditor {
private:
    string textBuffer;
    string clipboard;
    vector<shared_ptr<Command>> commandHistory;

public:
    void setText(const string& text) {
        textBuffer = text;
    }

    string getText() const {
        return textBuffer;
    }

    void copy() {
        clipboard = textBuffer; 
        cout << "Текст скопирован!" << endl;
    }

    void paste() {
        textBuffer += clipboard; 
        cout << "Скопированный текст вставлен!" << endl;
    }

    void deleteText() {
        textBuffer.clear(); 
        cout << "Текст удален!" << endl;
    }

    void addCommand(shared_ptr<Command> command) {
        command->execute();
        commandHistory.push_back(command);
    }

    void undo() {
        if (!commandHistory.empty()) {
            commandHistory.back()->undo();
            commandHistory.pop_back();
            cout << "Последнее действие отменено!" << endl;
        }
        else {
            cout << "Нет действий для отмены!" << endl;
        }
    }

    string getClipboard() const {
        return clipboard;
    }
};

// Конкретная команда: Копирование текста
class CopyCommand : public Command {
private:
    TextEditor& editor;

public:
    CopyCommand(TextEditor& ed) : editor(ed) {}

    void execute() override {
        editor.copy();
    }

    void undo() override {
        
    }
};

// Конкретная команда: Вставка текста
class PasteCommand : public Command {
private:
    TextEditor& editor;

public:
    PasteCommand(TextEditor& ed) : editor(ed) {}

    void execute() override {
        editor.paste();
    }

    void undo() override {
        editor.setText(editor.getText().substr(0, editor.getText().size() - editor.getClipboard().size()));
    }
};

// Конкретная команда: Удаление текста
class DeleteCommand : public Command {
private:
    TextEditor& editor;
    string deletedText;

public:
    DeleteCommand(TextEditor& ed) : editor(ed) {}

    void execute() override {
        deletedText = editor.getText(); 
        editor.deleteText();
    }

    void undo() override {
        editor.setText(deletedText); 
    }
};
