# `themer`

Your theme's unique URL:

https://themer.dev/?colors.dark.accent0=%23da5673&colors.dark.accent1=%23f09199&colors.dark.accent2=%23eebf35&colors.dark.accent3=%238cc16d&colors.dark.accent4=%2381c7d4&colors.dark.accent5=%2351a8dd&colors.dark.accent7=%23b595cf&colors.dark.shade0=%23302833&colors.dark.shade1=%23073642&colors.dark.shade2=%23b19693&colors.dark.shade3=%23657B83&colors.dark.shade4=%23839496&colors.dark.shade6=%23EEE8D5&colors.dark.shade7=%23e9e4d4&colors.dark.shade5=%23f8fbf8&colors.dark.accent6=%23007bbb&colors.d%20%20%20%20ark.accent6=%23268785&colors.dark%20%20%20%20.shade5=%2393A1A1&colors.light.accent0=%23DC322F&colors.light.accent1=%23CB4B16&colors.light.accent2=%23B58900&colors.light.accent3=%23859900&colors.light.accent5=%23268BD2&colors.light.accent6=%236C71C4&colors.light.accent7=%23D33682&colors.light.shade0=%23FDF6E3&colors.light.shade1=%23EEE8D5&colors.light.shade2=%2393A1A1&colors.light.shade4=%23657B83&colors.light.shade5=%23586E75&colors.light.shade6=%23073642&colors.light.shade7=%23002B36&colors.l%20%20%20%20ight.accent4=%232AA198&co%20%20%20%20lors.light.shade3=%23839496&activeColorSet=dark&calculateIntermediaryShades.dark=false&ca%20%20%20%20lculateIntermediaryShades.light=false

If you find `themer` useful, here are some ways to support the project:

* Star [`themer` on GitHub](https://github.com/mjswensen/themer)
* Follow [@themerdev](https://twitter.com/themerdev) on Twitter
* [Send a tip through the Brave Browser](https://brave.com/the537), either on [the repository page](https://github.com/mjswensen/themer) or [the Web UI](https://themer.dev)
* Pay what you want when downloading your theme from [themer.dev](https://themer.dev)

# Installation instructions

## Alacritty

1. Paste the contents of `Alacritty/Themer.yml` into your Alacritty config file.
2. Select the desired theme by setting the `colors` config key to reference the scheme's anchor (i.e., `colors: *light` or `colors: *dark`).

## iTerm

1. Launch iTerm
2. Press `command`-`I` to open the iTerm preferences
3. Choose Colors > Color Presets... > Import... and choose the generated theme file (`iTerm/themer-iterm-dark.itermcolors` or `iTerm/themer-iterm-light.itermcolors`)

## Vim

Copy or symlink `Vim/ThemerVim.vim` to `~/.vim/colors/`.

Then set the colorscheme in `.vimrc`:

    " The background option must be set before running this command.
    colo ThemerVim

## VS Code

Copy (or symlink) the generated package directory into the VS Code extensions directory:

    cp -R 'VS Code/theme-themer-vscode' ~/.vscode/extensions/

Then reload or restart VS Code. The generated theme package should be in the list of installed extensions, and "Themer Dark" / "Themer Light" will be available in the list of themes.

## Windows Terminal

1. Open the Windows Terminal settings (`Ctrl`-`,`)
2. Add the contents of 'Windows Terminal/themer-dark.json' and 'Windows Terminal/themer-light.json' to the `schemes` array in `profile.json`
3. Set the `colorScheme` property to the desired scheme name ("Themer Dark" or "Themer Light") in the profiles section of `profile.json`, e.g.:

    "profiles": {
      "defaults": {
        "colorScheme": "Themer Dark"
      }
    }