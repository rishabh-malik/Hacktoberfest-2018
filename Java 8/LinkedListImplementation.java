class Node {
    public int data;
    public Node next;
    
    public Node() {
    
    }
    
    public Node(int data) {
        this.data = data;
        this.next = null;
    }
    
}

class LinkedList {
    private Node root;
    
    public LinkedList() {
        root = null;
    }
    
    public void insertNode(int data) {
        Node temp = root;  
        if(root == null) {
            root = new Node(data);
            return;
        }      
        while(temp.next!=null) temp = temp.next;        
        Node nn = new Node(data);
        temp.next=nn;       
    }
    
    public void insertBeg(int data) {
        Node temp = root;
        Node nn = new Node(data);
        nn.next = temp;
        root = nn;
    }
    
    public void insertAfter(int data, int value) {
        if(searchData(value)) {
            Node temp = root;
            Node nextn = root.next;
            Node prev = null;
            
            while(temp!=null) {
              if(temp.data == value) break;
              prev = temp;
              temp = temp.next;
              nextn = temp.next;
            }
            
            if(temp.next==null) {
                insertNode(data);
            }
            else {
                Node nn = new Node(data);
                temp.next = nn;
                nn.next = nextn;
            }
        }    
    }
    
    public void insertBefore(int data, int value) {
        if(searchData(value)) {
            Node temp = root;
            Node nextn = root.next;
            Node prev = null;
            
            while(temp!=null) {
              if(temp.data == value) break;
              prev = temp;
              temp = temp.next;
              nextn = temp.next;
            }
            
            if(prev==null) {
                insertBeg(data);
            }
            else {
                insertAfter(data,prev.data);
            }
        }    
    }
    
    public boolean searchData(int data) {
        Node temp = root;
        while(temp!=null) {
            if(temp.data == data) return true;
            temp = temp.next;
        }   
        return false;
    }
    
    public void deleteData(int data) {
        if(searchData(data)) {
            Node temp = root;
            Node prev = null;
            
            while(temp!=null) {
              if(temp.data == data) break;
              prev = temp;
              temp = temp.next;
            }
            
            if(prev == null) {
                root = temp.next;
            }
            else if(temp.next==null) {
                prev.next = null;
            }
            else {
                prev.next = temp.next;
            }
        }
        else {
            System.out.println("Data doesn't exist");
        }
    }
    
    public void printList() {
        Node temp = root;
        if(temp == null) {
            System.out.println("List is empty");
            return;
        }
        
        while(temp!=null) {
            System.out.print(temp.data+" ");
            temp = temp.next;
        }   
        System.out.println();     
    }

}

class LinkedListDriver {

    public static void main(String[] args) {
    
        LinkedList list = new LinkedList();
        list.printList();
        list.insertNode(1);
        list.printList();
        list.insertBeg(0);
        list.printList();
        list.insertAfter(2,0);
        list.printList();
        list.insertAfter(3,2);
        list.printList();
        list.insertBefore(4,1);
        list.printList();
    }
}
