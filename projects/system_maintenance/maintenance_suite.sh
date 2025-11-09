#!/bin/bash
# ============================================
# System Maintenance Suite
# ============================================

LOG_FILE="/var/log/system_maintenance.log"

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root." | tee -a "$LOG_FILE"
    exit 1
fi

trap 'echo "[$(date)] ERROR: Command failed at line $LINENO" | tee -a "$LOG_FILE"' ERR

while true; do
    clear
    echo "============================================"
    echo "   🔧 System Maintenance Suite"
    echo "============================================"
    echo "1. Run System Backup"
    echo "2. Run System Update & Cleanup"
    echo "3. Run Log Monitoring"
    echo "4. Exit"
    echo "============================================"
    read -p "Enter your choice [1-4]: " choice

    case $choice in
        1)
            ./backup.sh
            ;;
        2)
            ./update_and_cleanup.sh
            ;;
        3)
            ./log_monitor.sh
            ;;
        4)
            echo "Exiting..."; exit 0;;
        *)
            echo "Invalid option! Try again."; sleep 2;;
    esac
done
