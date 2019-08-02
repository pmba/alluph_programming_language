ListNode* newListNode(Token* token) {

    ListNode* new_list_node = malloc(sizeof(ListNode));
    new_list_node->token = token;
    new_list_node->next = NULL;

    return new_list_node;
}

ListNode* pushList(ListNode* head, Token* token) {

    if(head == NULL) {
        head = newListNode(token);
    } else {

        ListNode* aux = head;

        while(aux->next != NULL) {
            aux = aux->next;            
        }

        aux->next = newListNode(token);        
    }  

    return head;
}

Token* nextToken() {

    if (TokenList == NULL) {

        analyseLine();
    }

    if (TokenList->next == NULL){
        Token* aux = TokenList->token;
        TokenList = NULL;

        return aux;
    } 
     
    else {
        Token* aux = TokenList->token;
        TokenList = TokenList->next;

        return aux;
    }
}

void printList (ListNode* head) {

    if(head != NULL) {

        ListNode* aux = head;
        
        while(aux != NULL) {
            printToken(aux->token);
            aux = aux->next;
        }

        free(aux);
    } else {
        printf("Empty list\n");
    }
}