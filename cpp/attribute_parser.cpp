// attribute parser
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

static const char BEG = '<';
static const char END = '>';

class TagNode {
    TagNode *_parent;
    //std::vector<TagNode*> _children;
    std::map<std::string, TagNode*> _children;
    
    std::map<std::string, std::string> _values;
    
    public:
    std::string _tag;
        TagNode(std::string);
        TagNode(std::string, TagNode*);
        ~TagNode();
        void add_value(std::string key, std::string val);
        void add_child(TagNode*);
        void print_tag();
        TagNode* get_parent();
        std::map<std::string, TagNode*> get_children();
        void query(std::stringstream&);
        void print_value(std::string);
};

TagNode::TagNode(std::string tag){
    _parent = nullptr;
    _tag = tag;
}

TagNode::TagNode(std::string tag, TagNode *parent){
    _parent = parent;
    _tag = tag;
}

TagNode::~TagNode(void){
    delete[] _parent;
    for (std::map<std::string,TagNode*>::iterator it = _children.begin() ; it != _children.end(); ++it){
     delete it->second;
    } 
    _children.clear();
}

void TagNode::add_value(std::string key, std::string val){
    std::pair<std::string, std::string> tmp(key,val);
    _values.insert(tmp);
}

void TagNode::add_child(TagNode* child){
    std::pair<std::string, TagNode*> nc(child->_tag, child);
    _children.insert(nc);
}

TagNode* TagNode::get_parent(){
    return _parent;
}

std::map<std::string, TagNode*> TagNode::get_children(){
    return _children;
}

void TagNode::print_tag(){
    if(_parent != nullptr){
        _parent->print_tag();
        std::cout << "->";
    }
    
    std::cout  << _tag;
}

void TagNode::print_value(std::string key){
    if(_values.find(key)!=_values.end()){
        std::cout<<_values[key]<<std::endl;
    } else {
        std::cout<<"Not Found!\n";
    }
}


void query(std::string q, TagNode* head){
    std::stringstream ss,qs;
    std::string tmp,tmp2;
    std::map<std::string,TagNode*> children;
    TagNode* curr = head;
    ss.str(q);
    
    while(std::getline(ss, tmp, '.')) {
        std::size_t it = tmp.find('~');
        if(it!=std::string::npos){
            children = curr->get_children();
            qs.str(tmp);
            std::getline(qs,tmp2, '~');
            std::string node = tmp2;
            std::getline(qs,tmp2, '~');
            std::string key = tmp2;
            
            if(children.find(node)!=children.end()){
                curr = children[node];
                curr->print_value(key);
            } else {
                std::cout<<"Not Found!\n";
            }
                
            
            //std::cout<<"\n--- node: "<<curr->_tag<<"\n--- key: "<<key<<"\n--- value: ";
            
        } else {
            children = curr->get_children();
            if(children.find(tmp)!=children.end()){
                 curr = children[tmp];
            } else if(ss.eof()){
                std::cout<<"Not Found!\n";
            }
               
        }
        
        
        //std::cout << tmp << std::endl;
    }
    //std::cout<< "exit\n";
}

TagNode* build_doc_tree(std::stringstream &ss){
    TagNode* head = new TagNode("HEAD");
    TagNode* curr = head; 
    //
    //curr->print_tag();
    //std::cout<<std::endl;
    //
    std::string tmp,trash;
    
    
    while(ss >> tmp){
        //std::cout << tmp << std::endl;
        if(!tmp.substr(0,2).compare("</")){
            curr = curr->get_parent();
            //
            //curr->print_tag();
            //std::cout << std::endl;
            //
        } else {
            if(tmp.front() == BEG){
                tmp.erase(tmp.begin());
                if(tmp.find('>')!=std::string::npos)
                    tmp.pop_back();
                TagNode* nn = new TagNode(tmp, curr);
                curr->add_child(nn);
                curr = nn;  
                //
                //curr->print_tag();
                //std::cout << std:: endl;
                //
            } else { 
                //std::cout<<"TMP: \"" << tmp << "\"" << std::endl;
                std::string k = tmp;
                ss >> trash >> tmp;
                tmp.erase(tmp.begin());
                if(tmp.find('>')!=std::string::npos)
                    tmp.pop_back();
                tmp.pop_back();
                curr->add_value(k,tmp);
                //std::cout<<"NEW VAL: (" << k << "," << curr->_values[k] << ")\n";
            }
        }
        
    }
    
    return head;
}


/*
===============================================================================
===============================================================================
===============================================================================
===============================================================================
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int lines, queries;
    std::vector<std::string> tags,qs;
    std::string str;
    std::stringstream ss;
       
    std::cin >> lines >> queries;
    for (int i = 0; i <= lines; i++){
        getline(std::cin,str);
        ss << str + " ";
        //std::cout << str << std::endl;
    }
    
    TagNode* head;
    head = build_doc_tree(ss);
    ss.str("");
    
    for (int i = 0; i < queries; i++){
        getline(std::cin,str);
        //std::cout << "query: " << i << std::endl;
        query(str,head);
        //std::cout<<std::endl;
    }
    
    
    return 0;
}
