SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* after_head1 = nullptr;
    
    SinglyLinkedListNode* merge_current_cusor = head2;
    SinglyLinkedListNode* merge_previous_cusor = nullptr;
    
    bool break_now = false;
    
    while (head1 != nullptr) {
        after_head1 = head1->next;
        break_now = false;
        
        while (merge_current_cusor != nullptr) {
            if(head1->data <= merge_current_cusor->data){
                
                if(merge_previous_cusor == nullptr){
                    head2 = head1;
                }else {
                    merge_previous_cusor->next = head1;
                }
                
                head1->next = merge_current_cusor;
                
                merge_current_cusor = head1;
                                
                break;
            }else if (merge_current_cusor->next == nullptr) {
                head1->next = nullptr;
                merge_current_cusor->next = head1;
                merge_previous_cusor = nullptr;
                break;
            }else {
                merge_previous_cusor = merge_current_cusor;
                merge_current_cusor = merge_current_cusor->next;
                
            }
        }
        head1 = after_head1;
    }

   return head2; 

}
