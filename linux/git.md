# Delete commit 

Notice the + sign before the name of the branch you are pushing, this tells git to force the push. It is worth to mention that you should be very careful when deleting commits because once you do it they are gone forever. Also, if you are deleting something from a remote repository make sure you coordinate with your team to prevent issues.

````sh
# Remove last 2 commits
$ git rebase -i HEAD~2

# Push to master without making a commit
$ git push origin +master
````


# Git tricks

Remove all items from git index (not working directory or local repo) and then update the Git index while respecting git ignores. Index=cache

````sh

	# Remove all items from git index
	git rm -r --cached .
	
	# Add them all back
	git add .

	git commit -am "Remove ignored files"

````
