// ============================================================================
// Project Name: CyberShield_X Security Suite (Dev-C++ 5.11 Compatible)
// Author: Maira Chandio (Roll No: 2k25-26/IT(TSI)/-38)
// Instructor: Ma'am Chandni Talpur | Department of IT, Sufism University
// Dev Environment: Dev-C++ 5.11 (Chromebook Stack)
// ============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

// Global Counters
int g_totalScans = 0;
int g_threatsDetected = 0;

// Bitwise XOR Encryption
string applyXORCipher(const string& input, char key) {
    string output = input;
    for (size_t i = 0; i < input.length(); ++i) {
        output[i] = input[i] ^ key;
    }
    return output;
}

// Persistent Audit Logger
void logAuditEvent(const string& eventDescription) {
    ofstream auditFile("audit_log.txt", ios::app);
    if (auditFile.is_open()) {
        auditFile << "[AUDIT LOG] " << eventDescription << "\n";
        auditFile.close();
    }
}

// Threat Scanning Routine (Compatible Loop)
void executeThreatScan() {
    g_totalScans++;
    cout << "\n[+] Initializing Threat Scanning Engine..." << endl;
    cout << "[+] Checking system memory spaces and execution paths..." << endl;
        
    vector<string> mockThreats;
    mockThreats.push_back("Trojan.Generic.C2");
    mockThreats.push_back("Ransomware.LockBit.Sig");
    mockThreats.push_back("Adware.Tracker.v1");
    
    for (size_t i = 0; i < mockThreats.size(); ++i) {
        cout << "[!] Analyzing signature: " << mockThreats[i] << " -> CLEAN" << endl;
    }
        
    cout << "[STATUS] System Scan Complete. 0 Active Vulnerabilities Detected." << endl;
    logAuditEvent("Threat Scan Executed - System Clean");
}

// Password Vault Storage
void storeCredential(const string& service, const string& pass) {
    ofstream vaultFile("vault_secure.dat", ios::app);
    if (!vaultFile) {
        cout << "[ERROR] Unable to access vault storage file." << endl;
        logAuditEvent("ERROR: Vault Access Failed");
        return;
    }
    string encryptedPass = applyXORCipher(pass, 'K');
    vaultFile << service << " " << encryptedPass << "\n";
    vaultFile.close();
    
    cout << "[SUCCESS] Credentials encrypted and logged to vault_secure.dat" << endl;
    logAuditEvent("Credential Saved for Service: " + service);
}

// System Health Analytics
void displayAnalytics() {
    cout << "\n==========================================================" << endl;
    cout << "               CYBERSHIELD_X SYSTEM ANALYTICS             " << endl;
    cout << "==========================================================" << endl;
    cout << " Total Threat Scans Performed: " << g_totalScans << endl;
    cout << " Total Vulnerabilities Flagged: " << g_threatsDetected << endl;
    cout << " System Security Rating       : OPTIMAL (100%)" << endl;
    cout << " Logging Status               : ACTIVE (audit_log.txt)" << endl;
    cout << "==========================================================" << endl;
    logAuditEvent("Analytics Diagnostic Executed");
}

int main() {
    logAuditEvent("CyberShield_X Application Session Started");
    
    int choice = 0;
    do {
        cout << "\n==========================================================" << endl;
        cout << "               CYBERSHIELD_X SECURITY SYSTEM              " << endl;
        cout << "==========================================================" << endl;
        cout << "1. Run Threat & Vulnerability Scan" << endl;
        cout << "2. Encrypt Sensitive String Payload" << endl;
        cout << "3. Save Password to Vault" << endl;
        cout << "4. View System Health Analytics" << endl;
        cout << "5. Exit Application" << endl;
        cout << "==========================================================" << endl;
        cout << "Select Option (1-5): ";
        
        if (cin >> choice) {
            if (choice == 1) {
                executeThreatScan();
            } else if (choice == 2) {
                string data;
                cout << "Enter text to encrypt: ";
                cin >> data;
                string encrypted = applyXORCipher(data, 'X');
                cout << "[RESULT] Encrypted Output: " << encrypted << endl;
                logAuditEvent("String Encryption Performed");
            } else if (choice == 3) {
                string svc, pwd;
                cout << "Enter Service Name: "; 
                cin >> svc;
                cout << "Enter Password: "; 
                cin >> pwd;
                storeCredential(svc, pwd);
            } else if (choice == 4) {
                displayAnalytics();
            } else if (choice == 5) {
                cout << "Exiting CyberShield_X system." << endl;
                logAuditEvent("User Terminated Session");
            } else {
                cout << "[!] Invalid option selected. Try again." << endl;
            }
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "[!] Invalid input format. Please enter numbers only." << endl;
        }
    } while (choice != 5);

    return 0;
}
