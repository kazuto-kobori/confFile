# `themer`

Your theme's unique URL:

https://themer.dev/?colors.dark.accent0=%23da5673&colors.dark.accent1=%23f596aa&colors.dark.accent2=%23eebf35&colors.dark.accent3=%238cc16d&colors.dark.accent4=%2381c7d4&colors.dark.accent5=%2351a8dd&colors.dark.accent7=%23b595cf&colors.dark.shade0=%233c2f41&colors.dark.shade1=%23073642&colors.dark.shade2=%23b19693&colors.dark.shade3=%23657B83&colors.dark.shade4=%23839496&colors.dark.shade6=%23EEE8D5&colors.dark.shade7=%23f7f1d5&colors.d%20%20%20%20ark.accent6=%23268785&colors.dark%20%20%20%20.shade5=%2393A1A1&colors.light.accent0=%23DC322F&colors.light.accent1=%23CB4B16&colors.light.accent2=%23B58900&colors.light.accent3=%23859900&colors.light.accent5=%23268BD2&colors.light.accent6=%236C71C4&colors.light.accent7=%23D33682&colors.light.shade0=%23FDF6E3&colors.light.shade1=%23EEE8D5&colors.light.shade2=%2393A1A1&colors.light.shade4=%23657B83&colors.light.shade5=%23586E75&colors.light.shade6=%23073642&colors.light.shade7=%23002B36&colors.l%20%20%20%20ight.accent4=%232AA198&co%20%20%20%20lors.light.shade3=%23839496&activeColorSet=dark&calculateIntermediaryShades.dark=false&ca%20%20%20%20lculateIntermediaryShades.light=false

If you find `themer` useful, here are some ways to support the project:

* Star [`themer` on GitHub](https://github.com/mjswensen/themer)
* Follow [@themerdev](https://twitter.com/themerdev) on Twitter
* [Send a tip through the Brave Browser](https://brave.com/the537), either on [the repository page](https://github.com/mjswensen/themer) or [the Web UI](https://themer.dev)
* Pay what you want when downloading your theme from [themer.dev](https://themer.dev)

# Installation instructions

## Alacritty

1. Paste the contents of `Alacritty/Themer.yml` into your Alacritty config file.
2. Select the desired theme by setting the `colors` config key to reference the scheme's anchor (i.e., `colors: *light` or `colors: *dark`).

## Brave

1. Launch Brave and go to `brave://extensions`.
2. Check the "Developer mode" checkbox at the top.
3. Click the "Load unpacked extension..." button and choose the desired theme directory (`Brave/Themer Dark` or `Brave/Themer Light`).

(To reset or remove the theme, visit `brave://settings` and click "Reset to Default" in the "Appearance" section.)

## Chrome

1. Launch Chrome and go to `chrome://extensions`.
2. Check the "Developer mode" checkbox at the top.
3. Click the "Load unpacked extension..." button and choose the desired theme directory (`Chrome/Themer Dark` or `Chrome/Themer Light`).

(To reset or remove the theme, visit `chrome://settings` and click "Reset to Default" in the "Appearance" section.)

## Emacs

Copy (or symlink) the generated theme files into `~/.emacs.d/`:

    cp 'Emacs/themer-dark-theme.el' ~/.emacs.d/
    cp 'Emacs/themer-light-theme.el' ~/.emacs.d/

Then load the desired theme in `init.el`:

    (load-theme 'themer-dark t)
    ;; or
    (load-theme 'themer-light t)

## Firefox Add-on

To use the generated extension package, the code will need to be packaged up and signed by Mozilla.

To package the code in preparation for submission, the `web-ext` tool can be used:

    npx web-ext build --source-dir 'Firefox Add-on/Themer Dark' # or 'Firefox Add-on/Themer Light'

Then the package can be submitted to Mozilla for review in the [Add-on Developer Hub](https://addons.mozilla.org/en-US/developers/addon/submit/distribution).

Learn more about Firefox themes from [extensionworkshop.com](https://extensionworkshop.com/documentation/themes/)

To theme Firefox without the need to create a developer account and go through the extension review process, see themer's integration with [Firefox Color](https://color.firefox.com).

## Firefox Color

The Firefox Color add-on allows for simple theming without the need for a developer account or package review process by Mozilla.

1. Install the [Firefox Color add-on](https://addons.mozilla.org/en-US/firefox/addon/firefox-color/).
2. Open 'Firefox Color/themer-dark.url' or 'Firefox Color/themer-light.url' directly with Firefox.
3. Click "Yep" when prompted to apply the custom theme.

For a more fully featured Firefox theme, see themer's Firefox theme add-on generator.

## iTerm

1. Launch iTerm
2. Press `command`-`I` to open the iTerm preferences
3. Choose Colors > Color Presets... > Import... and choose the generated theme file (`iTerm/themer-iterm-dark.itermcolors` or `iTerm/themer-iterm-light.itermcolors`)

## Konsole

Copy (or symlink) the generated files to `~/.local/share/konsole/`:

    cp 'Konsole/themer-dark.colorscheme' ~/.local/share/konsole/
    cp 'Konsole/themer-light.colorscheme' ~/.local/share/konsole/

Then choose the desired theme in Konsole > Settings > Edit Current Profile > Appearance.

## Sublime Text

1. Copy (or symlink) the generated theme files (`Sublime Text/themer-sublime-text-dark.tmTheme` or `Sublime Text/themer-sublime-text-light.tmTheme`) to the `User/` packages folder (you can see where this folder is located by choosing the "Browse Packages..." menu option in Sublime Text).
2. Choose the theme from the list of available color themes.

## Vim

Copy or symlink `Vim/ThemerVim.vim` to `~/.vim/colors/`.

Then set the colorscheme in `.vimrc`:

    " The background option must be set before running this command.
    colo ThemerVim

## Visual Studio

1. Select Tools > Import and Export Settings...
2. Choose the "Import selected environment settings" option
3. Choose whether or not to save a backup of current settings
4. Click "Browse..." and choose the generated theme file ('Visual Studio/themer-dark.vssettings' or 'Visual Studio/themer-light.vssettings')
5. Click "Finish"

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

## Xcode

Copy (or symlink) the generated theme files to Xcode's themes directory:

    mkdir -p ~/Library/Developer/Xcode/UserData/FontAndColorThemes
    cp 'Xcode/Themer Dark.dvtcolortheme' ~/Library/Developer/Xcode/UserData/FontAndColorThemes/
    cp 'Xcode/Themer Light.dvtcolortheme' ~/Library/Developer/Xcode/UserData/FontAndColorThemes/

Then restart Xcode. The themes will be available in Preferences > Fonts and Colors.

## Xresources

Copy the contents of 'Xresources/themer-dark.Xresources' or 'Xresources/themer-light.Xresources' into your .Xresources configuration file, or load it with `xrdb`.