#!/bin/bash
# ============================================
# System Update and Cleanup Script
# ============================================

LOG_FILE="/var/log/system_maintenance.log"

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root." | tee -a "$LOG_FILE"
    exit 1
fi

trap 'echo "[$(date)] ERROR: Command failed at line $LINENO" | tee -a "$LOG_FILE"' ERR

echo "[$(date)] Starting system update..." | tee -a "$LOG_FILE"
sudo apt update -y && sudo apt upgrade -y 2>>"$LOG_FILE"

echo "[$(date)] Performing cleanup..." | tee -a "$LOG_FILE"
sudo apt autoremove -y && sudo apt autoclean -y 2>>"$LOG_FILE"

echo "[$(date)] Maintenance complete." | tee -a "$LOG_FILE"
