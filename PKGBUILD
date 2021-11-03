pkgname="sstring"
pkgver="41.0.5"
pkgrel="5"
pkgdesc="Memory Safe String Library in C language."
arch=("x86_64" "i686")
conflicts=('sstring')
depends=(gcc)
license=("MIT")
source=(
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/sstring.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/prototype_err.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/binary.h"
  "https://raw.githubusercontent.com/Dark-CodeX/SafeString/main/sstring/morse_code.h")

sha512sums=(
  "cef655b25ca71d557e849bb49b4530ab52dc40cbde623989074ae11750ad68658e3f66fe0627d59c8ead529ea80b22b5d070a6228880d6199629fff7a5e087bc"
  "3bb43056cfcaf3c99d7b46194c986c943fc309f6f6c372da9c7abe7cbbd727c40b8eb37aea4c1baf117cca5546304b178ad941aebc29928416f557b43f5e23cf"
  "7384a1e59faab7c54efb1577292f3ba7b6d491e46ed893f8adc3e501f021ba62bcf02fc5f711f308484a835a91712bf8f947bd249dc6759338182bf4edf34cb1"
  "3758b1d37c84aaf1fe387702f5ab2236b29f993e466a7e311c444ed6946ec9accf458598720cab8f79032cfd0f08de85f7c2443f53ea5c94eeba58f94493e971")

package() {
  echo "Memory Safe String Library in C language."
  mkdir -p "${pkgdir}/usr/include/sstring"
  cp "${srcdir}/sstring.h" "${pkgdir}/usr/include/sstring/sstring.h"
  cp "${srcdir}/prototype_err.h" "${pkgdir}/usr/include/sstring/prototype_err.h"
  cp "${srcdir}/binary.h" "${pkgdir}/usr/include/sstring/binary.h"
  cp "${srcdir}/morse_code.h" "${pkgdir}/usr/include/sstring/morse_code.h"
  echo "Done!"
}
