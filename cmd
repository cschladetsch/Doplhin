for dir in */ ; do
  if [ -d "$dir/.git" ]; then
    # Remove trailing slash from directory name for submodule path
    dir=${dir%/}
    # Add the local repository as a submodule
    git submodule add "./$dir" "$dir"
  fi
done

