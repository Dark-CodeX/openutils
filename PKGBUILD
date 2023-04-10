pkgname="openutils-sstring"
pkgver="2.5.0"
pkgrel="8"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('openutils-sstring')
depends=(gcc)
license=("BSD 3-Clause License")
source=(
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/prototype_err.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/binary.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/morse_code.h"
	"https://raw.githubusercontent.com/Dark-CodeX/sstring/main/sstring/sstring.hh")

sha512sums=(
	"37949b65e3340738e985e22ce4183744b3bf6011af196e6ebd1786f40cc22966461e418ecdd9b519ac6febd249b6673fec0678efb7c8ae245901f767032b024e"
	"ec41d83646a7e3cda48e01db7b1bef6c22da36e18eff81ead769de7d4180d758be20a14089c3f41e2fb229877a2ce08e26db8a35aa49eee9ed56e71de3be0a0a"
	"07fa61299e4c272fe01d0b2fdf1c15cab017fd0b7752f45121799219cda357f580bb99cdf35a8f6774f5b0049ddd14d7b08f3bbaf22580dfd6447c5b58eccf51"
	"33b5cb57f42ba2df93f631bfad1f4447f659dc94c59ef2187e762b0d330a4885fa1490624acc32452786f72cb3e885e6d79d33f1b14d5670ba428c46ac77774c"
	"21376ee36c1adedb027fb4a944ba2d9273ee148e29a8a95b7ab54ac4db20426c9fe97ae435f7b44262923c464d3306d3aa838eeac7c12fbf4a4e750e4d611a45")

package() {
	echo "Memory Safe String Library in C language."
	mkdir -p "${pkgdir}/usr/include/openutils/sstring"
	cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/openutils/sstring/sstring.h"
	cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/openutils/sstring/prototype_err.h"
	cp "${srcdir}/binary.h" "${pkgdir}/usr/include/openutils/sstring/binary.h"
	cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/openutils/sstring/morse_code.h"
	cp "${srcdir}/sstring.hh" "${pkgdir}/usr/include/openutils/sstring/sstring.hh"
	echo "Done!"
}
