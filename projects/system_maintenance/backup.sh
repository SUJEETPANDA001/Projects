#!/bin/bash
# ============================================
# System Backup Script
# ============================================

SOURCE="/home"
DEST="/backup"
DATE=$(date +'%Y-%m-%d_%H-%M-%S')
BACKUP_FILE="$DEST/home_backup_$DATE.tar.gz"
LOG_FILE="/var/log/system_maintenance.log"

mkdir -p "$DEST"

if [ "$EUID" -ne 0 ]; then
    echo "Please run as root." | tee -a "$LOG_FILE"
    exit 1
fi

trap 'echo "[$(date)] ERROR: Command failed at line $LINENO" | tee -a "$LOG_FILE"' ERR

echo "[$(date)] Starting backup..." | tee -a "$LOG_FILE"
tar -czf "$BACKUP_FILE" "$SOURCE" 2>>"$LOG_FILE"

if [ $? -eq 0 ]; then
    echo "[$(date)] Backup successful: $BACKUP_FILE" | tee -a "$LOG_FILE"
else
    echo "[$(date)] Backup failed!" | tee -a "$LOG_FILE"
fi
