Helper 
void displayNode(SinglyLinkedListNode* head){
     SinglyLinkedListNode* cusor = head;
     cout << "###### DISPLAY NODE START" << "\n";
     int countor = 0;
     while (cusor != nullptr) {
        cout << cusor->data << "\n";
        cusor = cusor->next;  
        countor++;     
     }
     cout << "###### DISPLAY NODE END (count = " << countor << ")" << "\n";
 }

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    displayNode(head1);
    displayNode(head2);
    SinglyLinkedListNode* after_head1 = nullptr;
    
    SinglyLinkedListNode* merge_current_cusor = head2;
    SinglyLinkedListNode* merge_previous_cusor = nullptr;
    
    bool break_now = false;
    
    while (head1 != nullptr) {
        after_head1 = head1->next;
        break_now = false;
        
        while (merge_current_cusor != nullptr) {
            if(head1->data <= merge_current_cusor->data){
                
                
                cout << "\n\n[MODE BEFORE] Insertion of " << head1->data << endl;
                
                cout << "BEFORE" << endl;
                displayNode(head2);
                if(merge_previous_cusor == nullptr){
                    cout << "###### HEADER CHANGED" << endl;
                    head2 = head1;
                }else {
                    merge_previous_cusor->next = head1;
                }
                
                head1->next = merge_current_cusor;
                
                merge_current_cusor = head1;
                
                cout << "AFTER" << endl;
                displayNode(head2);
                cout << "Previous current = " << (merge_previous_cusor == nullptr ? "null" : to_string(merge_previous_cusor->data)) << endl;
                cout << "Cursor current = " << (merge_current_cusor == nullptr ? NULL : merge_current_cusor->data) << endl;
                
                break;
            }else if (merge_current_cusor->next == nullptr) {
                cout << "\n\n[MODE AFTER] Insertion of " << head1->data << endl;
                cout << "BEFORE" << endl;
                displayNode(head2);
                head1->next = nullptr;
                merge_current_cusor->next = head1;
                merge_previous_cusor = nullptr;
                cout << "AFTER" << endl;
                displayNode(head2);
                cout << "Previous current = " << (merge_previous_cusor == nullptr ? "null" : to_string(merge_previous_cusor->data)) << endl;
                cout << "Cursor current = " << (merge_current_cusor == nullptr ? NULL : merge_current_cusor->data) << endl;
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
