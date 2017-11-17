===Starting Everything Up===

1. Use keyboard shortcut Windows Key + R 
2. Type "cmd.exe" to open up command prompt
3. Type "cd Desktop/hw10" to change into the hw10 repository/directory




=====Pulling Down=====

1. type "git pull origin"
2. If there are merge conflicts, the command prompt will tell you in which files the conflicts are 
    occuring.  Open up the file with merge conflicts and look for something like <<<<<<HEAD<<<<<<
    That's where the conflict occured. Delete the correct section to remove the merge conflict




=====Pushing Up=====

1. Type "git add ." to add all files to staging area
2. Type "git commit -m"Commit Message"   The commit message is for saying what functionality you added/debugged etc...
3. Type "git push origin" to push up the changed files, along with you commit message.


