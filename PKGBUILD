pkgname="openutils-optional"
pkgver="1.6.0"
pkgrel="2"
pkgdesc="OPTIONAL : The Error Handling Library"
arch=("x86_64" "i686")
conflicts=('openutils-optional')
depends=(gcc)
license=("BSD 3-Clause License")
source=("https://raw.githubusercontent.com/Dark-CodeX/optional/master/optional/optional.hh")

sha512sums=("ea1e65905e12043b4a9c6cda4e9f698fe284a6cdc2a50ae47af8f58a9f7ad2ae28210f7349639c24666474d0863b1bda8298c3034e332cea1694ecc6195becfc")

package() {
	echo "OPTIONAL : The Error Handling Library"
	mkdir -p "${pkgdir}/usr/include/openutils/optional"
	cp "${srcdir}/optional.hh" "${pkgdir}/usr/include/openutils/optional/optional.hh"
	echo "Done!"
}
