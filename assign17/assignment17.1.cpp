#include <iostream>
#include <string>

using namespace std;

class Node {
protected:
    string title;
    int pages;
    Node* firstChild;
    Node* nextChild;

public:
    Node(const string& title, int pages) : title(title), pages(pages), firstChild(nullptr), nextChild(nullptr) {}

    void addChild(Node* node) {
        if (!firstChild) {
            firstChild = node;
        } else {
            Node* current = firstChild;
            while (current->nextChild) {
                current = current->nextChild;
            }
            current->nextChild = node;
        }
    }

    void print(int level = 0) const {
        for (int i = 0; i < level; ++i) {
            cout << "  ";
        }
        cout << title << " (" << pages << " pages)" << endl;
        if (firstChild) {
            firstChild->print(level + 1);
        }
        if (nextChild) {
            nextChild->print(level);
        }
    }

    virtual int countChapters() const {
        int count = 0;
        if (firstChild) {
            count += firstChild->countChapters();
        }
        if (nextChild) {
            count += nextChild->countChapters();
        }
        return count;
    }

    virtual int countChildren() const {
        int count = 0;
        Node* current = firstChild;
        while (current) {
            count++;
            current = current->nextChild;
        }
        return count;
    }

    virtual Node* findChapter(const string& title) {
        if (this->title == title) {
            return this;
        }
        if (firstChild) {
            Node* found = firstChild->findChapter(title);
            if (found) return found;
        }
        if (nextChild) {
            Node* found = nextChild->findChapter(title);
            if (found) return found;
        }
        return nullptr;
    }

    virtual Node* findLongestChapter() {
        return nullptr;
    }

    virtual void deleteNode(const string& title, Node*& parent) {
        if (firstChild && firstChild->title == title) {
            Node* temp = firstChild;
            firstChild = firstChild->nextChild;
            temp->nextChild = nullptr;
            delete temp;
            return;
        }

        Node* current = firstChild;
        while (current && current->nextChild) {
            if (current->nextChild->title == title) {
                Node* temp = current->nextChild;
                current->nextChild = current->nextChild->nextChild;
                temp->nextChild = nullptr;
                delete temp;
                return;
            }
            current = current->nextChild;
        }

        if (firstChild) {
            firstChild->deleteNode(title, firstChild);
        }
    }

    string getTitle() const {
        return title;
    }

    virtual ~Node() {
        delete firstChild;
        delete nextChild;
    }
};

class Chapter : public Node {
public:
    Chapter(const string& title, int pages) : Node(title, pages) {}
// dem so chapter
    int countChapters() const override {
        int count = 1; 
        if (firstChild) {
            count += firstChild->countChapters();
        }
        if (nextChild) {
            count += nextChild->countChapters();
        }
        return count;
    }
// tim chuong dai nhat
    Node* findLongestChapter() override {
        Node* longest = this;
        int maxChildren = this->countChildren();

        if (firstChild) {
            Node* childLongest = firstChild->findLongestChapter();
            int childMax = childLongest ? childLongest->countChildren() : 0;
            if (childMax > maxChildren) {
                longest = childLongest;
                maxChildren = childMax;
            }
        }
        if (nextChild) {
            Node* siblingLongest = nextChild->findLongestChapter();
            int siblingMax = siblingLongest ? siblingLongest->countChildren() : 0;
            if (siblingMax > maxChildren) {
                longest = siblingLongest;
            }
        }
        return longest;
    }
};

class Section : public Node {
public:
    Section(const string& title, int pages) : Node(title, pages) {}
};

class Subsection : public Node {
public:
    Subsection(const string& title, int pages) : Node(title, pages) {}
};

class Subsubsection : public Node {
public:
    Subsubsection(const string& title, int pages) : Node(title, pages) {}
};

int main() {
    Chapter* chapter1 = new Chapter("Chapter 1", 20);
    Section* section1 = new Section("Section 1.1", 10);
    Subsection* subsection1 = new Subsection("Subsection 1.1.1", 5);
    Subsubsection* subsubsection1 = new Subsubsection("Subsubsection 1.1.1.1", 3);

    Chapter* chapter2 = new Chapter("Chapter 2", 25);
    Section* section2 = new Section("Section 2.1", 15);

    chapter1->addChild(section1);
    section1->addChild(subsection1);
    subsection1->addChild(subsubsection1);

    chapter1->addChild(chapter2);
    chapter2->addChild(section2);

    chapter1->print();

    // 2. tim chuong dài nhat cua sach
    Node* longestChapter = chapter1->findLongestChapter();
    if (longestChapter) {
        cout << "chapter dai nhat: " << longestChapter->getTitle() << endl;
    } else {
        cout << "khong tim thay chapter." << endl;
    }

    // 3. xoa mot muc
    Node* temp = chapter1; 
    chapter1->deleteNode("Section 1.1", temp);
    chapter1->print();

    // 4. tim mot chuong va in de muc
    Node* foundChapter = chapter1->findChapter("Chapter 2");
    if (foundChapter) {
        cout << "chapter can tim: " << foundChapter->getTitle() << endl;
        foundChapter->print();
    } else {
        cout << "Chapter khong tim thay" << endl;
    }

    delete chapter1;

    return 0;
}


