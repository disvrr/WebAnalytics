This program reads two CSV files (day1.csv and day2.csv) containing user visits to product pages. It identifies users **who**:

    - Visited product pages on both days

    - On the second day, visited at least one product they hadn’t seen on the first day

  **  Preparing the CSV Files**

    Create two files named day1.csv and day2.csv

    Place them in the same folder as your .cpp file (or specify the full path in your code)

    Example content for day1.csv:
    u1,p1,2025-10-01T09:00:00
    u1,p2,2025-10-01T09:05:00
    u2,p3,2025-10-01T10:00:00
    Example for day2.csv:
    u1,p2,2025-10-02T09:00:00
    u1,p3,2025-10-02T09:10:00
    u2,p3,2025-10-02T10:00:00
    u2,p4,2025-10-02T10:10:00
    
    Running the Program in Visual Studio
    Open project in Visual Studio
    Press the "Start" button or use Ctrl + F5 to run
    The console will display the user IDs that match the criteria
    
    Example Output:
    Users who visited new product pages on the second day:
    u1
    u2
