pkgname="openutils-sstring"
pkgver="2.7.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C++ language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=("bb1c7d5af4cafc13583e40d82f9b5072a46d63511410de17728ecabcae0b5b32a294df84aa091a5ee0693dc939a57155d50e6861129b02d3d929297ddf50aa96")

package() {
	echo "Memory Safe String Library in C++ language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
