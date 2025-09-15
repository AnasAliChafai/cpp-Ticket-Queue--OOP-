<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Queue Management System</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; background-color: #f9f9f9; color: #333; padding: 20px; }
        h1, h2 { color: #2c3e50; }
        pre { background: #ecf0f1; padding: 10px; border-radius: 5px; overflow-x: auto; }
        ul { list-style-type: none; padding-left: 0; }
        li { margin: 5px 0; }
        .emoji { font-size: 1.2em; margin-right: 5px; }
        .section { margin-bottom: 20px; }
    </style>
</head>
<body>
    <h1>Queue Management System in C++</h1>

    <p>A console-based <strong>Queue Management System</strong> built with C++. 
    This project allows managing service queues with features such as issuing tickets, tracking waiting clients, serving clients, and displaying ticket details.</p>

    <div class="section">
        <h2>Features</h2>
        <ul>
            <li><span class="emoji">📋</span><strong>Show Queue Info</strong> → Display total tickets, served clients, and waiting clients.</li>
            <li><span class="emoji">➕</span><strong>Issue Ticket</strong> → Create a new ticket for the queue.</li>
            <li><span class="emoji">❌</span><strong>Serve Next Client</strong> → Remove the next client from the queue.</li>
            <li><span class="emoji">↔️</span><strong>Print Tickets</strong> → Display tickets RTL (newest → oldest) or LTR (oldest → newest).</li>
            <li><span class="emoji">💾</span><strong>Optional Persistence</strong> → Integrate with timestamp logging (requires <code>clsDate.h</code>).</li>
        </ul>
    </div>

    <div class="section">
        <h2>Project Structure</h2>
        <ul>
            <li><code>main.cpp</code> → Full application source code demonstrating queues.</li>
            <li><code>clsQueueLine.h</code> → Class definitions for queue and tickets.</li>
            <li><code>clsDate.h</code> → Utility for system date and time (needed for ticket timestamps).</li>
        </ul>
    </div>

    <div class="section">
        <h2>Usage Example</h2>
        <pre>
#include "clsQueueLine.h"

int main() {
    clsQueueLine PayBillsQueue("A0", 10);
    clsQueueLine SubscriptionsQueue("B0", 5);

    // Issue tickets
    PayBillsQueue.IssueTicket();
    PayBillsQueue.IssueTicket();

    // Display info and tickets
    PayBillsQueue.PrintInfo();
    PayBillsQueue.PrintTicketsLineRTL();
    PayBillsQueue.PrintTicketsLineLTR();

    // Serve one client
    PayBillsQueue.ServeNextClient();
    PayBillsQueue.PrintInfo();

    return 0;
}
        </pre>
    </div>

    <div class="section">
        <h2>Example Output</h2>
        <pre>
Pay Bills Queue Info:
____________________________________

        Queue Info
____________________________________

   Prefix : A0
   Total Tickets : 5
   Served Clients : 0
   Waiting Clients : 5
____________________________________

Tickets :  A01 <-- A02 <-- A03 <-- A04 <-- A05 <--
Tickets :  A05 --> A04 --> A03 --> A02 --> A01 -->
        </pre>
    </div>

    <div class="section">
        <h2>Requirements</h2>
        <ul>
            <li>C++11 or higher</li>
            <li><code>&lt;iomanip&gt;</code> for formatted output</li>
            <li><code>clsDate.h</code> file for timestamps</li>
        </ul>
    </div>

    <div class="section">
        <h2>Notes</h2>
        <ul>
            <li>Each queue works independently.</li>
            <li><code>ServeNextClient()</code> removes the first ticket permanently.</li>
            <li>Supports multiple queues simultaneously.</li>
        </ul>
    </div>
</body>
</html>
