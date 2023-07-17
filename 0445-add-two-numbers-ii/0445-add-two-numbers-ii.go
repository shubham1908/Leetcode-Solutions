/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    l1 = reverse(l1)
    l2 = reverse(l2)

    res := &ListNode{}
    head := res
    memo := 0
    for l1 != nil || l2 != nil {
        head.Next = &ListNode{
            Val: val(l1) + val(l2) + memo,
        }

        l1 = nodeNext(l1)
        l2 = nodeNext(l2)
        memo = 0
        head = head.Next
        if head.Val > 9 {
            memo = 1
            head.Val -= 10
        }
    }

    if memo > 0 {
        head.Next = &ListNode{
            Val: 1,
        }
    }

    return reverse(res.Next)
}

func val(l *ListNode) int {
    if l == nil {
        return 0
    }

     return l.Val
}

func nodeNext(l *ListNode) *ListNode {
    if l == nil {
        return nil
    }

    return l.Next
}

func reverse(head *ListNode) *ListNode {
    var resp *ListNode
    for head != nil {
        old := resp
        resp, head = head, head.Next
        resp.Next = old
    }
    
    return resp
}