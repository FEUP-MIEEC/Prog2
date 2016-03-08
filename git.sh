
git config --global user.name "Dannyps"
git config --global user.email "danny@dannyps.net"

git add .
#git checkout -b build
git commit --message "Travis build: $TRAVIS_BUILD_NUMBER"

# Force push from the current repo's master branch to the remote
# repo's gh-pages branch. (All previous history on the gh-pages branch
# will be lost, since we are overwriting it.) We redirect any output to
# /dev/null to hide any sensitive credential data that might otherwise be exposed.
git push --force --quiet "https://dannyps:${GH_TOKEN}@github.com/FEUP-MIEEC/Prog2" master:build


