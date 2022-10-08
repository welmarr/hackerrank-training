/**
 * Generate merge list from two sorted list. The method, here, is insert the
 * first list element is second list. Suppose List 1 [a1, a2, a2, ..., an] 
 * (a1 < a2 < ... <an) [1] and list 2 [b1, b2, b3, ..., bn] (b1 < b2 < b3 < ... < bn).
 * If I insert  a1 in list 2 maintaining the order of the list 2 and I have
 * [b1, b2, a1, b3, ..., bn], we'll have b2 < a1 < b3 [2]. According to [1] 
 * and [2] (a1 < a2 and b2 < a1 < b3), we have b2 < a2 and a2 will be inserted 
 * after b2.
 * 
 * @param head1 
 * @param head2 
 * @return SinglyLinkedListNode* 
 */
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
